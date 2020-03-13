#ifndef __ASSERT__
#define __ASSERT__

#define ERRCODE_ORA_PACKAGES_INVALID_SCHEMA_NAME \
      MAKE_SQLSTATE('4',                         \
    '4',                                         \
    '0',                                         \
    '0',                                         \
    '1')
#define ERRCODE_ORA_PACKAGES_INVALID_OBJECT_NAME \
      MAKE_SQLSTATE('4',                         \
    '4',                                         \
    '0',                                         \
    '0',                                         \
    '2')
#define ERRCODE_ORA_PACKAGES_ISNOT_SIMPLE_SQL_NAME \
      MAKE_SQLSTATE('4',                           \
    '4',                                           \
    '0',                                           \
    '0',                                           \
    '3')
#define ERRCODE_ORA_PACKAGES_ISNOT_QUALIFIED_SQL_NAME \
      MAKE_SQLSTATE('4',                              \
    '4',                                              \
    '0',                                              \
    '0',                                              \
    '4')

#endif
