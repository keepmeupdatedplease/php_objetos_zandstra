<?php
	require_once("DB.php");
	require_once('Chargeable.class.inc');

	class ShopProduct implements Chargeable {
		private $title = "default product";
		private $producerFirstName = "First name";
		private $producerMainName = "Main name";
		private $discount = 0;
		protected $price = 0;
		private $id=0;
		
		
		function __construct ($title, $producerFirstName, $producerMainName, $price, $discount) {
			$this->title = $title;
			$this->producerFirstName = $producerFirstName;
			$this->producerMainName = $producerMainName;
			$this->price = $price;
			$this->discount= $discount;
		}
		
		
		public function getProducer() {
			return "{$this->producerFirstName}" . " {$this->producerMainName}";
		}
		

		public function getSummaryLine() {
			$base = "{$this->title} ({$this->producerMainName}, ";
			$base .= "{$this->producerFirstName})";
			return $base;
		}
		
		public function getPrice() {
			return $this->price - $this->discount;
		}
		
		public function setDiscount ($discount) {
			$this->discount = $discount;
		}

		public function getDiscount () {
			return $this->discount;
		}
		
		
		public function getTitle(){
			return $this->title;
		}
		
		
		public function setID($id) {
			$this->id = $id;
		}
		
		
		public static function getInstance ($id, DB_common $db) {
			$query = "SELECT * FROM products ";
			$query .= "WHERE id='".$id."' ";
			
			$query_result = $db->query($query);
			
			if (DB::isError($query_result)) {
				die($query_result->getMessage());
			}
			
			$row = $query_result->fetchRow(DB_FETCHMODE_ASSOC);
			if (empty($row)) {return NULL; }

			switch($row['type']) {
				case "book":
					$product = new BookProduct(
						$row['title'],
						$row['firstname'],
						$row['mainname'],
						$row['price'],
						NULL,
						$row['numpages']
					);
					break;
					
				case "cd":
					$product = new CdProduct(
						$row['title'],
						$row['firstname'],
						$row['mainname'],
						$row['price'],
						NULL,
						$row['playlength']
					);
					break;
					
				default:
					$product = new ShopProduct(
						$row['title'],
						$row['firstname'],
						$row['mainname'],
						$row['price'],
						NULL
					);
					break;
			}
			
			$product->setId($row['id']);
			$product->setDiscount($row['discount']);
			
			return $product;
			
			
		}
		
		
	}


	
	class CdProduct extends ShopProduct {
		public $playLength;
		
		
		function __construct($title, $producerFirstName, $producerMainName, $price, $discount, $playLength) {
			$this->playLength = $playLength;
			parent::__construct($title, $producerFirstName, $producerMainName, $price, $discount);
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
		
		
		function __construct($title, $producerFirstName, $producerMainName, $price, $discount, $numPages) {
			$this->numPages = $numPages;
			parent::__construct($title, $producerFirstName, $producerMainName, $price, $discount);
		}
		
		function getSummaryLine() {
			$base = parent::getSummaryLine();
			$base .= ": Page count - {$this->numPages}";
			return $base;
		}
		
	}



























	
?>