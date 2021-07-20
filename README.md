# premake5cb (a.k.a. Premake5 exporter)

*Premake5 exporter* is a [Code::Blocks](https://www.codeblocks.org/) plugin to generate [Premake5](https://premake.github.io/docs/) scripts for Code::Blocks workspaces. This makes it possible to generate GNU Makefiles, MS Visual Studio solutions etc. from a C::B workspace.

## Overview by example

Starting with a Code::Blocks workspace *OPEN_CRD.workspace* with some contained projects, the *Premake5 exporter* plugin creates *OPEN_CRD_premake5.lua* in the same folder (see Figure 1 ). In a terminal, *premake5* is used to generate GNU Makefiles:
    
```
$ premake5 --file=OPEN_CRD_premake5.lua gmake2

Building configurations...
Running action 'gmake2'...
Generated buildpm5/Makefile...
Generated buildpm5/open_crd/Makefile...
Generated buildpm5/crd2pts/Makefile...
Done (50ms).
```

To build the code for all the projects in the workspace, run make:

```
$ cd buildpm5
make
```

**Figure 1 - Manual export to Premake5**

![Manual export](images/plugin_export.png)

```

```
## Settings

The plugin has user adjustable options, accessed via the Code::Blocks Plugins menu. The idea with the settings is to provide defaults for values that may not be directly available in the original Code::Blocks workspace or project files.

* First, defaults are applied from the GUI settings, i.e. on workspace, project and config levels.

* Second, values from Code::Blocks workspace, project and build targets may override or add new values.


**Figure 2 - Acessing the Premake5 exporter settings**

![](images/plugin_menu.png)


```

```
### General
Under *General*, settings include file name masks for files to be included and options to control the way the plugin works. 

* *Automatic export on build*  causes the premake5 script to be regenerated every time you compile in Code::Blocks, eliminating the need for manual export (ref. Figure 1). 

* *Use workspace prefix in premake5 filename* causes the simplified filename *premake5.lua*, to be prefixed with the workspace name, requiring --file=filename option in the premake5 command. 

* *Use workspace/projects defaults* causes these options to be applied before actual projevt values. 

* *Export project types* makes it possible to filter which project types to be exported. For example, wxWidgets applications is of type "WindowedApp" and may require special buildoptions and linkoptions.

* Pressing the *Restore factory settings* does the obvious thing, it resets all options back to their initial install state.

**Figure 3 - General**

![](images/plugin_general.png)


```

```
### Project defaults
There are  tabs for defining premake5 code snippets for workspace, project and configuration filters (the workspace defaults work in the same way as the project defaults, only on workspace level). These settings are applied before the Code::Blocks projects are examined, so they are to be considered initial default values.

**Figure 4 - Project defaults**

![](images/plugin_project.png)

```

```
### Config defaults

The Config defaults contain filters for Debug and Release, and are roughly equivalent to Code::Blocks build targets. The plugin supports 2 predefined configuration filters: *debug* and *release*

**Figure 4 - Config defaults**

![](images/plugin_config.png)

```

```


## Features

In order to make things work, some assumptions have been made. This may imply that not all Code::Blocks workspaces will export and build without manual adjustment, but some will. Sometimes, just a bit of manual edit/additions are required.  At the time of writing, the plugin builds under Linux only. Constructive suggestions to enable Windows build are welcome, consider creating a pull request. In any case, the generated Premake5 scripts can be used for generating [Windows builds](https://premake.github.io/docs/Using-Premake) as well as GNU Makefiles.

* A Code::Blocks workspace file must exist, the workspace projects must be stored under the workspace folder (long paths are ok).

* Projects such as static libraries, shared libraries and console applications are supported. 

* Projects using wxWidgets are initially not directly supported, but the ambition is to improve this. A preliminary linux-only work around for this issue is to add options similar to the following in the config dialogs.

```
    buildoptions { "`wx-config --version=3.0 --cxxflags`" }
    linkoptions { "`wx-config --version=3.0 --libs`" }
```
* Projects with C/C++ source files are assumed, but this can be adjusted with file name filters. C++ language dialect settings such as -std=c++17 in Code::Blocks settings are passed on to premake5, as well as possible preprocessor #defines.

* Code::Blocks project dependencies within a workspace are handled on premake export. Include and link paths are automatically managed. It is important to note that when a project links to another project in the same Premake5 workspace, the reference is to project name, not library name. The plugin handles this automatically.

* External dependencies can be managed by the user using premake5 commands [includedirs](https://premake.github.io/docs/includedirs/) and [libdirs](https://premake.github.io/docs/libdirs/) in either workspace defaults, project defaults or in configs. See also [Premake documentation](https://premake.github.io/docs/) for other possibilites in dealing with external dependencies. It is possible to use environment variables in such commands, but be aware when something like ${ENVIRONMENT_VARIABLE} is required in the settings dialog, it must be written as $[ENVIRONMENT_VARIABLE] with square brackets for the time being.


```

```

## Example workspace

See [https://github.com/arnholm/pm5example1](https://github.com/arnholm/pm5example1) for a complete example.

