<?php

class LinkedList
{
    public $head;
    public $tail;

    public function __construct()
    {
        $this->head = null;
        $this->tail = null;

        return $this;
    }

    public function getHead(): Node
    {
        return $this->head;
    }

    public function getTail(): Node
    {
        return $this->tail;
    }

    public function addToHead(Node $node): LinkedList
    {
        $first = $node->setNext($this->head);
        $this->head = $first;

        return $this;
    }

    public function addToTail(Node $node): LinkedList
    {
        if ($this->head === null) {
            $this->head = $node;
            $this->tail = $node;
        } else {
            $this->tail->setNext($node);
            $this->tail = $node;
        }
        return $this;
    }

    public function removeFromHead(): LinkedList
    {
        $this->head = $this->head->getNext();
        return $this;
    }

    public function removeFromTail(): LinkedList
    {
        $current = $this->head;
        while ($current->getNext()->getNext() !== null) {
            $current = $current->getNext();
        }
        $current->setNext(null);
        $this->tail = $current;

        return $this;
    }

    public function reverse(): LinkedList
    {
        $previous = null;
        $current = $this->head;
        $preceding = $current->getNext();

        $this->tail = $this->head;
        while ($preceding !== null) {
            $current->setNext($previous);
            $previous = $current;
            $current = $preceding;
            $preceding = $preceding->getNext();
        }

        $current->setNext($previous);
        $this->head = $current;

        return $this;
    }

    public function print(): void
    {
        if ($this->head === $this->tail) {
            /**
             * Only one node in the list
             */
            echo $this->head->getValue();
        } else {
            $current = $this->head;
            while ($current !== null) {
                echo $current->getValue() . '->';
                $current = $current->getNext();
            }
        }
        echo PHP_EOL;
    }
}
