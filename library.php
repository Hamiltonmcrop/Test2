#!/usr/bin/php
<?php
class Book {
    private $title;
    private $author;
    private $isbn;
    private $available;

    public function __construct($title, $author, $isbn) {
        $this->title = $title;
        $this->author = $author;
        $this->isbn = $isbn;
        $this->available = true;
    }

    public function displayBookInfo() {
        echo "Title: " . $this->title . "\n";
        echo "Author: " . $this->author . "\n";
        echo "ISBN: " . $this->isbn . "\n";
    }

    public function checkAvailability() {
        if ($this->available) {
            echo $this->title . " is available.\n";
        } else {
            echo $this->title . " is checked out.\n";
        }
    }

    public function checkOutBook() {
        if ($this->available) {
            $this->available = false;
            echo $this->title . " has been checked out.\n";
        } else {
            echo $this->title . " is already checked out.\n";
        }
    }

    public function returnBook() {
        if (!$this->available) {
            $this->available = true;
            echo $this->title . " has been returned.\n";
        } else {
            echo $this->title . " is already available.\n";
        }
    }
}

// Create three different book objects
$book1 = new Book("The Catcher in the Rye", "J.D. Salinger", "123456789");
$book2 = new Book("To Kill a Mockingbird", "Harper Lee", "987654321");
$book3 = new Book("1984", "George Orwell", "456789123");

// Display book information
$book1->displayBookInfo();
$book2->displayBookInfo();
$book3->displayBookInfo();

// Check availability
$book1->checkAvailability();
$book2->checkAvailability();
$book3->checkAvailability();

// Check out and return books
$book1->checkOutBook();
$book1->checkAvailability();
$book1->returnBook();
$book1->checkAvailability();
?>
