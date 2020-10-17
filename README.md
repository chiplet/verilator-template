# verilator-template
Template for starting up new projects using verilator.

# Setup

### macOS
1. Install verilator. This is most conveniently done with [homebrew](https://brew.sh/)

`brew install verilator`

2. Check your verilator version

`verilator --version`

3. Modify the `VV` variable in `TEMPLATE/Makefile` to match your verilator version.

# Usage
To create a new project simply run the script

`./new_module.sh module-name`

where `module-name` is the name you want to give to your new verilog module. This creates a new project directory called `module-name` from the project template in specified in `TEMPLATE/`.
