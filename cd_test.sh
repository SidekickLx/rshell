#!/bin/sh
echo "current path" `pwd`
echo "----------------------"
echo "testing cd bin"
cd bin
echo "curent path:"  `pwd`
echo "----------------------"
echo "testing cd -"
cd -
echo "curent path:" `pwd`
echo "----------------------"
echo "testing cd"
cd
echo "curent path:" `pwd`

