# physics-engine

This C++/Qt5.7 project is a simulation of springy & viscous materials using a damped spring model, composed of 16 nodes connected by damped springs. Each square of 4 nodes acts as an element with its own internal pressure.
<br>Click and drag nodes using the left mouse button, fix them in place with the right. Adjust physics coefficients with the sliders:
<br>MASS: Controls the mass of all nodes
<br>SPRING COEFFICIENT: Coefficient of the springs' resistance to being extended or compressed. Higher value = tighter spring.
<br>DAMPING COEFFICIENT: Coefficient of the springs' resistance to velocity.
<br>RESISTANCE: Rough simulation of friction and air resistance that is a multiplied by the velocity of each node. 0-> No movement, 100-> No resistance to velocity. Value of 100 may result in gradual increase of velocity due to floating point rounding errors.
<br>INTERNAL PRESSURE: Coefficient of pressure acting on each node from the centre of mass of the elements it is part of.

PRESS RESET to reset the nodes to their original positions and velocity.
<b>Note that the starting resistance is 0, so until this is turned up the nodes will not move.</b>
 
Limitations:
1. INVERSION- Currently nodes are able to cross over springs. This results in the internal pressure calculations driving nodes around the screen.
2. COEFFICIENTS- The maximum viable value of the coefficients is dependent on each other and this is not yet accounted for in the simulation, so certain configurations may cause the nodes to fly off the screen. In this case the simulation will automatically be reset.
