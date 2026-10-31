/*
 * The following are some useful utility functions inside the std::filesystem namespace: 
 *
 * –– std::filesystem::create_directory                 for creating a directory 
 * –– std::filesystem::copy                             for copying files and directories 
 * –– std::filesystem::remove                           for removing a file or an empty folder 
 * –– std::filesystem::remove_all                       for removing folders and subfolders
 * -- std::filesystem::path	                            The path class represents the path of the directory or the file.
 * -- std::filesystem::copy_options	                    This class represents the available copy options.
 * -- std::filesystem::directory_options	            Represents the options for iterating through directory contents.
 * -- std::filesystem::filesystem_error	                This class defines the exceptions that are thrown by the filesystem functions in case of errors.
 * -- std::filesystem::file_status	                    This class stores information about the type of the file and available permissions.
 * -- std::filesystem::file_time_type	                It represents file time values
 * -- std::filesystem::perms	                        This function stores the information about the file access permission.
 * -- std::filesystem::perm_options	                    It specifies the semantics of permissions operations.
 * -- std::filesystem::space_info	                    This struct stores the data about the storage in the specified path.
 * -- std::filesystem::file_type	                    It is used to represent different types of a file or directory.
 * -- std::filesystem::directory_entry                  a directory entry
 * -- std::filesystem::directory_iterator               an iterator to the contents of the directory
 * -- std::filesystem::recursive_directory_iterator     an iterator to the contents of a directory and its subdirectories
 * 
 * Non-member functions
 *  -- Defined in header <filesystem>
 *  -- Defined in namespace std::filesystem
 * 
 *  -- std::filesystem::absolute                        composes an absolute path
 *  -- std::filesystem::canonical                       composes a canonical path
 *  -- std::filesystem::weakly_canonical                composes a canonical path
 *  -- std::filesystem::relative                        composes a relative path
 *  -- std::filesystem::proximate                        composes a relative path
 *  -- std::filesystem::copy                            copies files or directories
 *  -- std::filesystem::copy_file                       copies file contents
 *  -- std::filesystem::copy_symlink                    copies a symbolic link
 *  -- std::filesystem::create_directory                creates new directory
 *  -- std::filesystem::create_directories              creates new directory
 *  -- std::filesystem::create_hard_link                creates a hard link
 *  -- std::filesystem::create_symlink                  creates a symbolic link
 *  -- std::filesystem::create_directory_symlink        creates a symbolic link
 *  -- std::filesystem::current_path                    returns or sets the current working directory
 *  -- std::filesystem::exists                          checks whether path refers to existing file system object
 *  -- std::filesystem::equivalent                      checks whether two paths refer to the same file system object
 *  -- std::filesystem::file_size                       returns the size of a file
 *  -- std::filesystem::hard_link_count                 returns the number of hard links referring to the specific file
 *  -- std::filesystem::last_write_time                 gets or sets the time of the last data modification
 *  -- std::filesystem::permissions                     modifies file access permissions
 *  -- std::filesystem::read_symlink                    obtains the target of a symbolic link
 *  -- std::filesystem::remove                          removes a file or empty directory  
 *  -- std::filesystem::remove_all                      removes a file or directory and all its contents, recursively
 *  -- std::filesystem::rename                          moves or renames a file or directory
 *  -- std::filesystem::resize_file                     changes the size of a regular file by truncation or zero-fill
 *  -- std::filesystem::space                           determines available free space on the file system
 *  -- std::filesystem::status                          determines file attributes
 *  -- std::filesystem::symlink_status                  determines file attributes, checking the symlink target
 *  -- std::filesystem::temp_directory_path             returns a directory suitable for temporary files
 *
 * File types:
 * 
 *  -- std::filesystem::is_block_file                   checks whether the given path refers to block device
 *  -- std::filesystem::is_character_file               checks whether the given path refers to a character device
 *  -- std::filesystem::is_directory                    checks whether the given path refers to a directory
 *  -- std::filesystem::is_empty                        checks whether the given path refers to an empty file or directory
 *  -- std::filesystem::is_fifo                         checks whether the given path refers to a named pipe
 *  -- std::filesystem::is_other                        checks whether the argument refers to an other file
 *  -- std::filesystem::is_regular_file                 checks whether the argument refers to a regular file
 *  -- std::filesystem::is_socket                       checks whether the argument refers to a named IPC socket
 *  -- std::filesystem::is_symlink                      checks whether the argument refers to a symbolic link
 *  -- std::filesystem::status_known                    checks whether file status is known
 *
 * std::filesystem::path subcommand:
 * 
 * Decomposition:
 * std::filesystem::path(<path>).root_name              returns the root-name of the path, if present
 * std::filesystem::path(<path>).root_directory         returns the root directory of the path, if present
 * std::filesystem::path(<path>).root_path              returns the root path of the path, if present
 * std::filesystem::path(<path>).relative_path          returns path relative to the root path
 * std::filesystem::path(<path>).parent_path            returns the path of the parent path
 * std::filesystem::path(<path>).filename               returns the filename path component
 * std::filesystem::path(<path>).stem                   returns the stem path component (filename without the final extension)
 * std::filesystem::path(<path>).extension              returns the file extension path component
 * 
 * Queries:
 * 
 * std::filesystem::path(<path>).empty                  checks if the path is empty
 * std::filesystem::path(<path>).has_root_path          checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_root_name          checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_root_directory     checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_relative_path      checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_parent_path        checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_filename           checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_stem               checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).has_extension          checks if the corresponding path element is not empty
 * std::filesystem::path(<path>).is_absolute            checks if root_path() uniquely identifies file system location
 * std::filesystem::path(<path>).is_relative            checks if root_path() uniquely identifies file system location

*/

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::cout << "Argc -> " << argc << "\n";

    std::vector<std::string> args;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            args.push_back(argv[i]);
        }
    }

    std::filesystem::path cDrive = "C:\\temp3\\";

    if (std::filesystem::exists(cDrive))
    {
        std::cout << cDrive << " exists!\n";
    } else {
         std::cout << cDrive << " does not exists!\n";
    }

    std::filesystem::path config = "C:\\config.ini";

    if (std::filesystem::exists(config))
    {
        std::cout << config << " exists!\n";
    } else {
         std::cout << config << " does not exists!\n";
    }

    std::cout << "File name -> " << std::filesystem::path(config).filename() << "\n";
    std::cout << "Root name -> " << std::filesystem::path(config).root_name() << "\n";
    std::cout << "Root Directory -> " << std::filesystem::path(config).root_directory() << "\n";
    std::cout << "Root Path -> " << std::filesystem::path(config).root_path() << "\n";
    std::cout << "Extension -> " << std::filesystem::path(config).extension() << "\n";
    std::cout << "Relative Path -> " << std::filesystem::path(config).relative_path() << "\n";
    std::cout << "Is Absolute -> " << (std::filesystem::path(config).is_absolute() ? "True": "False") << "\n";
    std::cout << "Is Relative -> " << (std::filesystem::path(config).is_relative() ? "True": "False") 
              << " -> " << std::filesystem::path(config).relative_path() << "\n";
    std::cout << "Has root name -> " << (std::filesystem::path(config).has_root_name() ? "True": "False") 
              << " -> " << std::filesystem::path(config).root_name() << "\n";
    std::cout << config << " is block file -> " << (std::filesystem::is_block_file(config) ? "True": "False") << "\n";
    std::cout << config << " is character file -> " << (std::filesystem::is_character_file(config) ? "True": "False") << "\n";
    std::cout << config << " is directory -> " << (std::filesystem::is_directory(config) ? "True": "False") << "\n";
    std::cout << config << " is empty -> " << (std::filesystem::is_empty(config) ? "True": "False") << "\n";
    std::cout << config << " is fifo file -> " << (std::filesystem::is_fifo(config) ? "True": "False") << "\n";
    std::cout << config << " is regular file -> " << (std::filesystem::is_regular_file(config) ? "True": "False") << "\n";
    std::cout << config << " is socket -> " << (std::filesystem::is_socket(config) ? "True": "False") << "\n";
    std::cout << config << " is symbolic like file -> " << (std::filesystem::is_symlink(config) ? "True": "False") << "\n";
    std::cout << config << " size is -> " << std::filesystem::file_size(config) << " bytes\n";

    auto myFolder = "C:\\temp\\ss";

    std::cout << "\nList C:\\temp\\ss folder : \n\n";

    // This will only stop at level 1 and will not list contents of subdirectories
    for (auto f : std::filesystem::directory_iterator(myFolder))
    {
        std::cout << f << "\n";
    }

    // This will list contents of subdirectories
    std::cout << "\nCheck recursively : \n\n";

    for (auto f : std::filesystem::recursive_directory_iterator(myFolder))
    {
        std::cout << f << "\n";
    }

    std::cout << "__FILE__ -> " << __FILE__ << '\n';
    // std::cout << std::filesystem::path(__FILE__).remove_filename() << '\n';

    return 0;
}