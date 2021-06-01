# verilator-template
Template for starting up new projects using verilator.

# Setup

### macOS
1. Install verilator. This is most conveniently done with [homebrew](https://brew.sh/)

`brew install verilator`

2. Check your verilator version

`verilator --version`

3. Modify the `VV` variable in `TEMPLATE/Makefile` to match your verilator version.

4. Install gtkwave

`brew cask install gtkwave`

On macOS the command `gtkwave` doesn't seem to work properly when run from the command line.
A workaround can be found [here](https://web.archive.org/web/20210117151608/http://labnote.me/gtkwave-macos-commandline-param/)

# Usage
To create a new project simply run the script

`./new_module.sh module-name`

where `module-name` is the name you want to give to your new verilog module. This creates a new directory `module-name/` based on the project template specified in `TEMPLATE/`.
