unix-tools
==========

## wc 

wc  file-name           

Example ->    `wc  one.txt`

It will be display word count,character count and lines count presented in this given file.


## head

.. head -[No of lines]  file-name

Example ->  `head -5 one.txt`

It will be display first 5 lines from given file.

.. head file-name 
           
Example -> `head one.txt`

It will be display default first 10 lines from given file.


## tail

.. tail -[No of lines]  file-name

Example ->  `tail -5 one.txt`

It will be display last 5 lines from given file.

.. tail file-name 
           
Example -> `tail one.txt`

It will be display default last 10 lines from given file.

## uniq

uniq file-name

Example -> `uniq one.txt`

It will be display uniq lines among the entire file

## sort

.. sort file-name

Example -> `sort one.txt`

It will be display all content of the file by sorting ascending order.

.. sort -r file-name

Example -> `sort -r one.txt`

It will be display all content of the file by decending order.


## cut
.. cut -c[number of character] file-name

Example -> `cut -c3 one.txt`

It will be display third number character of every line of given file.

.. cut -f[number of fields] file-name

Example -> `cut -f1 one.txt`

It will be display all record in given file

.. cut -f[number of fields] -d[delimeter] file-name

Example -> `cut -f1 -d" " one.txt`

It will be display the first field of every line from given file.

## reduce space

reducespace file-name

Example -> `reducespace one.txt`

It will be remove all extra spaces from the given file.
