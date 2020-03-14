# Oracle Database Compatibility Features for Postgres

**Table of Contents**

* [Background](#background)
* [Goals](#goals)
* [Overview](#overview)
* [Installation](#installation)
* [Configuration](#configuration)
* [Usage](#usage)
* [Architecture](#architecture)
* [Frequently Asked Questions \(FAQ\)](#frequently-asked-questions)
* [License](#license)
* [Contributors](#contributors)
* [Additional Resources](#additional-resources)

## Background

Often referred to as the world’s most advanced open source relational database, with over 30 years of active development, [Postgres](https://www.postgresql.org/) has earned a reputation for its reliability, feature robustness, and performance. While it has long been considered an enterprise-grade database, in the past, Postgres was overlooked in favor of commercial databases, such as [Oracle Database](https://www.oracle.com/database/) and [Microsoft SQL Server](https://www.microsoft.com/en-us/sql-server/default.aspx).

In many cases, the propensity to choose a commercial database over Postgres was due to a lack of awareness, user-friendly tools, and support organizations. Over the last decade, however, a number of [PostgreSQL derivations](https://wiki.postgresql.org/wiki/PostgreSQL_derived_databases) and companies emerged to not only fill those gaps, but [double Postgres' popularity](https://db-engines.com/en/ranking_trend/system/PostgreSQL).

Over that same period of time, [commercial relational database systems declined](https://db-engines.com/en/ranking_trend/relational+dbms). Even though the popularity of commercial databases declined, their licensing costs increased. As a result, Postgres became an attractive target for migration from these commercial databases. Unfortunately, porting an existing application from one database to another is not a trivial task.

Although most enterprise-grade relational databases provide similar data types, SQL syntax, and procedural languages, each vendor tends to deviate fairly heavily from the standards. As a consequence, both syntactic and semantic differences exist between database engines. Accordingly, migrating an application from one database to another often requires a significant investment in identifying incompatibilities, rewriting incompatible parts, and retesting. That's why, if you use Oracle Database and want to migrate to Postgres or develop an application on Postgres that could one day be moved to Oracle, this extension has much to offer by way of compatibility.

For many years, Oracle Database has been considered the gold standard of enterprise database systems. In terms of cutting-edge features, availability, and performance, Oracle Database is generally unmatched. The majority of developers and DBAs, however, use very few proprietary features Oracle Database provides. Upon recognizing the need for providing application-oriented interoperatibility for this subset of functionality, both to and from Oracle Database, this project was created.

This extension represents the culmination of that multi-year collaborative effort.

## Goals

The goal of this project is to provide an open-source PostgreSQL extension that promotes application-oriented interoperability with Oracle Database by means of compatible data type, function, and package implementations.

At a high-level, this extension should:

* **Support Migration from Oracle Database** - Applications written for use with Oracle Database should be significantly easier to migrate to Postgres using the features provided by this extension.
* **Support Migration to Oracle Database** - An application written for Postgres, using the features provided by this extension in lieu of Postgres-specific ones, should be significantly easier to migrate to Oracle Database.
* **Compliment Existing Oracle Environments** - Most enterprises have deployed multiple database systems, open source and commercial. The features provided by this extension should provide DBAs and developers with a level of database agnosticism and general familiarity that simplifies interaction with Oracle and Postgres.
* **Target Common Features Only** - Statistically, studies indicate only twenty to thirty percent of an application's features are frequently used. While Oracle Database contains a lot of cool features, this is an unfunded open source project. Unless an implementation is sponsored, follow the [Pareto Principle](https://en.wikipedia.org/wiki/Pareto_principle#In_computing) and prioritize implementations by frequency of utilization.

---

## Overview

This extension provides Postgres-native implementations of the following features compatible with Oracle Database:

* [Data Types](#built-in-data-types)
* [SQL Functions](#built-in-sql-functions)
* [PL/SQL Packages](#built-in-plsql-packages)
* [Schema Objects](#built-in-schema-objects)

Additionally, this extension provides the following features not included in Oracle Database:

* [PL/Vision Compatible Library](documentation/docs/third-party/plvision/README.md) - A subset of Steven Feuerstein's once-popular library of PL/SQL functions ported to Postgres.
* [PL/Unit Compatible Testing Framework](documentation/docs/third-party/plunit/README.md) - A minimal implementation of the lightweight PL/SQL unit testing package ported to Postgres.

---

### Built-in Data Types

This extension provides the following Postgres-native implementations of data types similar to, and compatible with, Oracle Database.

| Data Type | Description |
|:------------|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [`NVARCHAR2(n)`](documentation/docs/built-in/datatypes/NVARCHAR2.md) | A variable-length character string with a maximum length of *n characters*. |
| [`VARCHAR2(n)`](documentation/docs/built-in/datatypes/VARCHAR2.md) | A variable-length character string with a maximum length of *n bytes*. |

Note:

* Unlike Oracle, our VARCHAR2 and NVARCHAR2 implementations do not impose the 4000 byte limit on the *declared* size. In fact, it is same as PostgreSQL's VARCHAR, which is about 10MB - although VARCHAR can theoretically store values of size up to 1GB.
* Unlike Oracle Database, which allows you to select BYTE or CHARACTER semantics, PostgreSQL does not support dynamic specification. That being the case, we cannot support both semantics for the same type. As BYTE semantics are the default in Oracle Database, VARCHAR2 has been implemented such that the length modifier represents BYTE semantics. Conversely, NVARCHAR2 has been implemented such that the length modifier represents CHARACTER semantics.
* As each character in a multibyte-encoded character set may be composed of an arbitrary number of bytes, be careful when storing strings using VARCHAR2.

---

### Built-in SQL Functions

This extension provides the following Postgres-native implementations of SQL functions similar to, and compatible with, Oracle Database.

---

### Built-in PL/SQL Packages

This extension provides the following Postgres-native implementations of PL/SQL packages similar to, and compatible with, Oracle Database:

| Package Name | Description |
|:------------|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [`DBMS_ALERT`](documentation/docs/built-in/packages/DBMS_ALERT.md) | Provides functionality for registering for, sending, and receiving alerts. |
| [`DBMS_ASSERT`](documentation/docs/built-in/packages/DBMS_ASSERT.md) | Provides functionality for protecting user input against SQL injection. |
| [`DBMS_OUTPUT`](documentation/docs/built-in/packages/DBMS_OUTPUT.md) | Provides functionality for buffering messages. |
| [`DBMS_PIPE`](documentation/docs/built-in/packages/DBMS_PIPE.md) | Provides functionality for sending messages between sessions through a pipe. |
| [`DBMS_RANDOM`](documentation/docs/built-in/packages/DBMS_RANDOM.md) | Provides functionality for generating random values. |
| [`DBMS_SQL`](documentation/docs/built-in/packages/DBMS_SQL.md) | Provides functionality for handling dynamic SQL. |
| [`DBMS_UTILITY`](documentation/docs/built-in/packages/DBMS_UTILITY.md) | Provides miscellaneous functionality. |
| [`UTL_FILE`](documentation/docs/built-in/packages/UTL_FILE.md) | Provides functionality for reading from, and writing to, operating system files. |

---

### Built-in Schema Objects

This extension provides the following Postgres-native implementations of schema objects similar to, and compatible with, Oracle Database.

### DUAL Table

As the FROM clause is a mandatory component of queries in Oracle Database, the DUAL table is used for cases where no table name is necessary. While Postgres does not require this clause, the DUAL table has been re-created to permit compatibility with common SQL queries.

### Catalog Views

This extension provides the following catalog views, which provide information about Postgres database objects in a format compatible with the commonly-used Oracle Database data dictionary:

| View | Description |
|:------------|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `dba_segments` | Storage allocated for all database segments. |
| `product_componenent_version` | Version and status information for component products. |
| `user_cons_columns` | Information about accessible columns in constraint definitions. |
| `user_constraints` | Constraint definitions on user's own tables. |
| `user_objects` | Objects owned by the user. |
| `user_tab_columns` | Columns of user's tables and views. |
| `user_tables` | Provides a description of the user's own relational tables |

---

## Installation

This extension is normally distributed as a PostgreSQL "contrib" module. To install it from a pre-configured source tree run the following commands as a user with appropriate privileges from the orafce source directory:

```
export NO_PGXS=1
make
make install
```

Alternatively, if you have no source tree you can install using PGXS. Simply
run the following commands the adminpack source directory:

```
make
make install
```

To install Orafce functions in the database, either run the orafce.sql script 
using the pgAdmin SQL tool (and then close and reopen the connection to the 
freshly instrumented server), or run the script using psql, eg:

```
CREATE EXTENSION orafce;
```

Other administration tools that use this module may have different requirements,
please consult the tool's documentation for further details.

This package requires PostgreSQL 9.4 or later.

---

## Configuration

This module supports the following configuration options:

* `orafce.nls_date_format` (string) - Emulate the DATE data type output behavior in Oracle Database. (default = NULL)
* `orafce.timezone` (string) - The time zone to use for the SYSDATE function. (default = GMT)
* `orafce.varchar2_null_safe_concat` (boolean) ** - Emulate NULL as an empty string during character string concatenation similar to Oracle Database. (default = false)

---

## Usage

---

## Architecture

### High-level System Architecture

### High-level Software Architecture

### Repository Architecture

A high-level overview of the files in this repository.

* **./README.md** - This file.
* **./docs/** - End-user documentation for this extension.
* **./scripts/** - Utility scripts.
* **./sql/** - SQL for creating required catalogs et al.
* **./src/** - Source code.
* **./test/** - Test code.

---

## Frequently Asked Questions

A few questions and answers.

* **I don't see feature X?**

	Please submit a ticket...

---

## License

See the [License](LICENSE).

---

## Contributors

The project was founded in 2008 by Pavel Stehule.

Considerable additional development has been added to this project by Jonah H. Harris and NEXTGRES, LLC.

A full list of contributors can be found [here](AUTHORS).

---

## Additional Resources

### Community & Help

* [Google Group](https://groups.google.com/forum/?hl=en#!forum/orafce-general)

### Tools

### Documentation

* [Detailed Changelog](CHANGELOG.md)
