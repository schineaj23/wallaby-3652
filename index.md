## Botball 2018 Project Base

The puropse of this code is to
have a project base for Botball. This code is being maintained and updated actively most likely up until the end of the Botball 2018 season, although this will still be used as a project base by Parkside Robotics until further stated.

### Features

- Basic Movement and Veering
- Edge Tracking
- Line Tracking
- Camera Operations
- Motor Tracking and Sensing

### Simplicity

The PKMS Framework is Customizable without sacrificing simplicity.
All features are as simple as calling a function! No need to link a .lib simply add the files!
For example, a line tracking program.

```c
#include "util.h"

int main()
{ 
    trackLine();

    return 0;
}
```

### Support

If you find any bugs, have any questions or issues, feel free to open an Issue on the repo. Please be clear about all of your problems and we'll be happy to help!

### Documentation

Documentation can be found [here](./doc). Documentation is constantly evolving and is still experimental, so don't expect much at the moment!