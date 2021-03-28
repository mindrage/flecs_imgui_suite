# Flecs Imgui Suite

This project main goal is to provide runtime tooling for the C/C++ ECS library called Flecs.



**Legend**

  ☐ = Not yet started  
  ☒ = In Progress  
  ☑ = Complete

**Features**

 - ☒ Entity Overview  
  The entity overview shows all components, children and composition of selected entities.
  Components are currently shown as list items, but are planned to be columns.
 
 - ☐ System Overview  
  This widget is to display all active systems and allow for actions such as toggling, changing intervals and more.
 
 - ☐ Component Overview  
  This acts as a widget to see all registered components within a world, with the ability to highlight which ones are shown in the Entity Inspect, as well as show which ones are available for an focused entity.
 
 - ☐ Singleton Overview  
  Singletons are shared global structs that are used within systems. The overview is meant to list and edit values.
 
 - ☐ Entity Popup  
  The entity popup is meant as a popup context to preview an entity inside the world.  
  It will have to be triggered manually with a screen coord to give flexiblity for implementation.  
  All component editors will be shown vertically as well as a child / relation tree.

 - ☐ Profiler  
  A Profiler to get time and execution for each system (Might integrate with System Overview)  
  Flecs already provides some detailed remote profilers through [flecs.dash](https://github.com/flecs-hub/flecs-dash)

 - ☐ Prefab Editor   
  A prefab editor to organize children and other components, maybe a export functionality?


# Usage

Include the main header first.

```cpp
#include <flecs_imgui_suite.h>
```
