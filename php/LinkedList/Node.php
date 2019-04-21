<?php

class Node
{
    private $value;
    private $next = null;

    public function __construct(int $value)
    {
        $this->value = $value;
        return $this;
    }

    public function getNext()
    {
        return $this->next;
    }

    public function setNext($node): Node
    {
        $this->next = $node;
        return $this;
    }

    public function getValue(): int
    {
        return $this->value;
    }

    public function setValue(int $value): Node
    {
        $this->value = $value;
        return $this;
    }
}