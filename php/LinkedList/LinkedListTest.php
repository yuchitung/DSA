<?php
include_once "LinkedList.php";
include_once "Node.php";

/**
 * create an empty list and add 4 nodes to the list
 */
echo 'Add 4 nodes to list:' . PHP_EOL;
$node1 = new Node(10);
$node2 = new Node(20);
$node3 = new Node(30);
$node4 = new Node(40);
$list = new LinkedList();
$list->addToTail($node1)
    ->addToTail($node2)
    ->addToTail($node3)
    ->addToTail($node4)
    ->print();
/**
 * Add a new node to the front of the list
 */
echo 'Add a new node to the front of the list:' . PHP_EOL;
$node5 = new Node(0);
$list->addToHead($node5)->print();

/**
 * Reverse the list;
 */

echo 'Reverse:' . PHP_EOL;
$list->reverse()->print();

echo 'Remove a node from head:' . PHP_EOL;
$list->removeFromHead()->print();

echo 'Remove a node from tail:' . PHP_EOL;
$list->removeFromTail()->print();

echo 'Get head:'. PHP_EOL;
echo $list->getHead()->getValue(). PHP_EOL;

echo 'Get tail:'. PHP_EOL;
echo $list->getTail()->getValue(). PHP_EOL;
