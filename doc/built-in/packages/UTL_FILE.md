# Open Source Implementation of UTL\_FILE

This package allows PL/pgSQL prgrams read from and write to any files that are accessible from server. Every session can open maximaly ten files and max line size is 32K. This package contains functions:

* `utl_file.fclose(file utl_file.file_type)` - close file
* `utl_file.fclose_all()` - close all files
* `utl_file.fcopy(src_location, src_filename, dest_location, dest_filename[, start_line][, end_line])` - copy text file
* `utl_file.fflush(file utl_file.file_type)` - flushes all data from buffers
* `utl_file.fgetattr(location, filename)` - get file attributes
* `utl_file.fopen(location text, filename text, file_mode text [, maxlinesize int] [, encoding name]) utl_file.file_type` - open file
* `utl_file.fremove(location, filename)` - remove file
* `utl_file.frename(location, filename, dest_dir, dest_file[, overwrite])` - rename file
* `utl_file.get_line(file utl_file.file_type) text` - read one line from file
* `utl_file.get_nextline(file utl_file.file_type) text` - read one line from file or returns NULL
* `utl_file.is_open(file utl_file.file_type) bool` - returns true, if file is opened
* `utl_file.new_line(file utl_file.file_type [,rows int])` - puts some new line chars to file
* `utl_file.put(file utl_file.file_type, buffer text)` - puts buffer to file
* `utl_file.put_line(file utl_file.file_type, buffer text)` - puts line to file
* `utl_file.putf(file utl_file.file_type, format buffer [,arg1 text][,arg2 text][..][,arg5 text])` - put formated text into file
* `utl_file.tmpdir()` - get path of temp directory

Because PostgreSQL doesn't support call by reference, some function's are gently different:

* `fclose` and `get_line`.

```sql
  declare f utl_file.file_type;
  begin
    f := utl_file.fopen('/tmp', 'sample.txt', 'r');
    <<readl>>
    loop
      begin
        raise notice '%', utl_file.get_line(f);
      exception
        when no_data_found then
          exit readl;
      end;
    end loop;
    f := fclose(f);
  end; 
```

or second (with PostgreSQL specific function `get_nextline`)

```sql
    declare 
      f utl_file.file_type;
      line text;
    begin
      f := utl_file.fopen('/tmp', 'sample.txt', 'r');
      loop
        line := utl_file.get_nextline(f);
        exit when line is NULL;
        raise notice '%', line;
    exception
      when others then
        utl_file.fclose_all();
    end;
```

Before using package you have to set table `utl_file.utl_file_dir`. This contains all allowed directories without ending symbol ('/' or '\'). On WinNT platform you have to put locality parametr with ending symbol '\' everytime.

