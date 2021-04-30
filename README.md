# Shortest-Path-special
A shortest path algorithm with special input

Overview

Given H amount of number h<sub>1</sub>,h<sub>2</sub>,...,h<sub>H</sub> and V amount of number v<sub>1</sub>,v<sub>2</sub>,...,v<sub>V</sub>
Horizontally H, Vertically V, H*V amount of vertex is arranged in a matrix.
These vertex make up a directional graph.
Let V<sub>i,j</sub> be the vertex at i<sup>th<sup> row and j<sup>th</sup> column.
From every V<sub>i,j</sub>, there are three directional edge going to V<sub>i+1,j</sub>,V<sub>i,j+1</sub>,V<sub>i+1,j+1</sub>.
Given H amount of number h<sub>1</sub>,h<sub>2</sub>,...,h<sub>H</sub> and V amount of number v<sub>1</sub>,v<sub>2</sub>,...,v<sub>V</sub>
,the cost of each of these edges is the absolute difference between h<sub>i</sub> and v<sub>j<sub>.
This algorithm finds the shortest path of the given graph

Input
H X
h<sub>1</sub>,h<sub>2</sub>,...,h<sub>H</sub>
v<sub>1</sub>,v<sub>2</sub>,...,v<sub>V</sub>

Output
three matrixes of H*V size.
The first matrix gives the cost of the edges going from the vertex.
The second matrix gives the total cost needed to go from 0,0 to that vertex.
The third matrix prints out the parent of the current vertex.
