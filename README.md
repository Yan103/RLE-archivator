# The RLE-archiver

RLE Archiver is a useful program that can help you compress your data. The algorithm archives repeated characters in the number/character format, that is, a sequence of consecutive 100 characters, you can get a sequence of 2 characters. This is most effective for data containing many repetitions, such as simple graphical images such as icons, line drawings, games, and animations. For files that don't have many repetitions, encoding them with RLE can increase the file size.

If your data contains a sequence of more than 1 character, then this entire part of the file will be overwritten in 2 characters. However, if your data contains single characters (ABCD...), then this entire sequence (up to the first "series" of repeated characters) will be written in the format #ABCD...#, if 1 character is written between two repeated "series", then it will be overwritten as #A#.


## Installation and compilation
To run the program on your computer, download the repository and run the Makefile
1. Cloning a repository
```bash
https://github.com/Yan103/RLE-archivator
```
2. Compilation of source files
```bash
make
```
3. Start
```bash
make run
```
4. Optional: remove files (deleting object and executable files)
```bash
make clean
```

## Examples of work
Below are examples of how my algorithm works

If you need to encode a large sequence where there are repeated characters, then the algorithm does an excellent job of this task (in the example, the algorithm made 26 out of the original 101 characters):

![Alt text](img/ex2.png)

However, if your data is a set of unique characters, then it is better not to use this algorithm (in the example, the program processed an article from Wikipedia about the LRE archiver ~ 7700 symbols):

![Alt text](img/ex1.png)

## Contact information
If you are interested in this project or have any questions/suggestions about the project, you can contact the author:

Mail: fazleev.yans@phystech.edu

Telegram: @yan_ya_n3

![Alt Text](https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif)

