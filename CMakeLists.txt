cmake_minimum_required(VERSION 3.26)
project(851)

set(CMAKE_CXX_STANDARD 17)

add_executable(851 main.cpp
        list/sqlist.h
        list/linklist.h
        list/doublelinklist.h
        list/listT.h
        stack/stackT.h
        stack/sqstack.h
        stack/linkstack.h
        queue/sqqueue.h
        queue/queueT.h
        queue/linkqueue.h
        tree/sqbitree.h
        tree/linkbitree.h
        tree/treeT.h
        sort/insert.h
        sort/sortT.h
        tree/threadbitree.h
        unionfindset/unionfind.h
        graph/agraph.h
        graph/mgraph.h
        graph/graphT.h
        graph/bfs.h
        graph/dfs.h
        graph/prim.h
        graph/distance.h
        sort/quick.h
        graph/kruskal.h
        graph/dijkstra.h
        graph/floyd.h
        graph/topologicalsort.h
        search/sqsearchtable.h
        search/searchT.h
        search/binarysorttree.h
        sort/binaryinsert.h
        sort/shell.h
        sort/bubble.h
        sort/select.h
        sort/heap.h
        sort/merge.h
        algo/divide_and_conquer/chessboard.h
        algo/algoT.h
        algo/dynamic_programming/matrixchain.h
        algo/dynamic_programming/lis.h
        algo/dynamic_programming/lcs.h
        algo/dynamic_programming/maxsum.h
        algo/dynamic_programming/pack.h)
