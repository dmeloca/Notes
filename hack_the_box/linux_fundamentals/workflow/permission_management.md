# Permision Management

Linux permissions control access to files and directories. Each file or directory has:
- An **owner (user)**
- An associated **group**
- Permissions for **owner**, **group**, and **others**

## Basic Permissions
Linux uses three basic permissions:
- **Read (r)**: View file contents or list directory contents
- **Write (w)**: Modify a file or create/delete files in a directory
- **Execute (x)**: Run a file or traverse a directory

```Shell
- rwx rw- r--   1 root root 1641 May  4 23:42 /etc/passwd
- --- --- ---   |  |    |    |   |__________|
|  |   |   |    |  |    |    |        |_ Date
|  |   |   |    |  |    |    |__________ File Size
|  |   |   |    |  |    |_______________ Group
|  |   |   |    |  |____________________ User
|  |   |   |    |_______________________ Number of hard links
|  |   |   |_ Permission of others (read)
|  |   |_____ Permissions of the group (read, write)
|  |_________ Permissions of the owner (read, write, execute)
|____________ File type (- = File, d = Directory, l = Link, ... )
```

## Directory Permissions
- Execute permission on a directory is required to **enter or traverse** it.
- Without execute permission, users cannot access directory contents.
- Write permission on a directory allows creating, deleting, or renaming files.

## Permission Representation
Permissions are displayed in:
- **Symbolic format**: `rwxr-xr--`
- **Octal format**: `754`

Each permission has a numeric value:
- `r = 4`, `w = 2`, `x = 1`
- Values are added for owner, group, and others.

## Changing Permissions
- Permissions are modified using the `chmod` command.
- Example:
  ```bash
  chmod 754 file
  ```

```Shell
Binary Notation:                4 2 1  |  4 2 1  |  4 2 1
----------------------------------------------------------
Binary Representation:          1 1 1  |  1 0 1  |  1 0 0
----------------------------------------------------------
Octal Value:                      7    |    5    |    4
----------------------------------------------------------
Permission Representation:      r w x  |  r - x  |  r - -
```
## Changing Ownership
- Ownership is modified using `chown`
- `chown user:group file`

## Special permissions
- **SUID**: Program runs with the file owner's privileges.
- **SGID**: Program runs with the file group's privileges.
- These permisions could be dangerous if misused.

## Sticky Bit
- Applied to directories to restirct file deletion.
- Only the file owner, directory owner, or root can delte files.
- `t` indicates execute permission is set.
- `T` indicates execute permission is not set.

