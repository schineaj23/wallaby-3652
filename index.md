## Botball 2018 Project Base

The puropse of this code is to
have a project base for Botball. This code is being maintained and updated actively most likely up until the end of the Botball 2018 season, although this will still be used as a project base by Parkside Robotics until further stated.

### Features

- Basic Movement and Veering
- Edge Tracking
- Line Tracking
- Camera Operations
- Motor Tracking and Sensing

### Examples

This is a simple track line program.

```c
#include "chassis.h"
#include "util.h"

int main()
{
    skipLine(FORWARD, 2);
    
    trackLine();

    return 0;
}


```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/schineaj23/wallaby-3652/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
