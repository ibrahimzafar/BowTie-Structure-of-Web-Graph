# Graphs
This repository explores the Bow-Tie Structure that is characteristic of many graphs. 


## Author
You can get in touch with me on <a class="btn-linkedin" href="https://www.linkedin.com/in/ibrahim-zfr/">LinkedIn</a>!

If you liked my repository, kindly support my work by giving it a ⭐!


## About this Repository
The following research papers were studied:
https://www.researchgate.net/publication/200111010_Mining_the_Inner_Structure_of_the_Web_Graph
http://snap.stanford.edu/class/cs224w-readings/broder00bowtie.pdf
http://cs.wellesley.edu/~pmetaxas/Why_Is_the_the_Web_a_Bowtie.pdf


![alt text](https://github.com/ibrahimzafar/Graphs/blob/master/bowtie.PNG "Bow Tie Structure") <br>
Picture taken from Broder et. al.

The Bow-Tie structure of the Epinions social network was used, using the dataset made available by Stanford. 
https://snap.stanford.edu/data/soc-Epinions1.html



The following method was used to compute the components of the Web Graph was as follows: 
1) Compute SCC of the epinions network. 

2) Run BFS on any randomly selected node from SCC. This gives us SCC+OUT. We can now use this to get total nodes in OUT.<br>
##### OUT = (SCC+OUT)-SCC

3) Run BFS on any randomly selected node from SCC, on the graph’s complement. This gives us SCC+IN. We can now use this to get total nodes in IN. This is the same as running BFS on the in-links of the node.<br>
##### IN = (SCC+IN)-SCC

4) Now make the graph bidirectional and compute weakly connected components. <br>

5) Running BFS/DFS on weakly connected components gives us the large connected structure in one traversed path, and disconnected nodes in the other traversed paths <br>
##### TENDRILS+TUBES = CONNECTED - (SCC + OUT + IN)

6) Finally, compute the disconnected nodes of the graph. <br>
##### DISCONNECTED = V - CONNECTED <br>



The components of the epinions network given by this implementation are as follows:<br>


|   Component    |   Number of Nodes   |
|:-----------:|:----------:|
|SCC          |32220       |
|IN           |24228       |
|OUT          |    15455   |
|TENDRILS+TUBES|3966        |
|DISCONNECTED | 19         |

## Contributions are Welcome!
Feel free to improves the code by generating a pull request!<br>


## License
[MIT License](https://github.com/ibrahimzafar/Graphs/blob/master/LICENSE.md)



