<?php

	class ShopProduct {
		public $title = "default product";
		public $producerFirstName = "First name";
		public $producerMainName = "Main name";
		public $price = 0;
		
		
		function __construct ($title, $producerFirstName, $producerMainName, $price) {
			$this->title = $title;
			$this->producerFirstName = $producerFirstName;
			$this->producerMainName = $producerMainName;
			$this->price = $price;
		}
		
		
		function getProducer() {
			return "{$this->producerFirstName}" . " {$this->producerMainName}";
		}
		

		function getSummaryLine() {
			$base = "{$this->title} ({$this->producerMainName}, ";
			$base .= "{$this->producerFirstName})";
			return $base;
		}


	}


	
	class CdProduct extends ShopProduct {
		public $playLength;
		
		
		function __construct($title, $producerFirstName, $producerMainName, $price, $playLength) {
			$this->playLength = $playLength;
			parent::__construct($title, $producerFirstName, $producerMainName, $price);
		}
		
		function getPlayLength() {
			return $this->playLength;
		}
		
		
		function getSummaryLine() {
			$base = parent::getSummaryLine();
			$base .= ": play length - {$this->playLength}";
			return $base;
		}
		
	}
		

	class BookProduct extends ShopProduct {
		public $numPages;
		
		
		function __construct($title, $producerFirstName, $producerMainName, $price, $numPages) {
			$this->numPages = $numPages;
			parent::__construct($title, $producerFirstName, $producerMainName, $price);
		}
		
		function getSummaryLine() {
			$base = parent::getSummaryLine();
			$base .= ": Page count - {$this->numPages}";
			return $base;
		}
		
	}



























	
?>