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
		

		public function


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
		
	}
		
		
		

	
?>