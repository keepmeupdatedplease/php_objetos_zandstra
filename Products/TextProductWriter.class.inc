<?php

class Products_TextProductWriter extends Products_ShopProductWriter {
	
	public function write() {
		$str = "PRODUCTS:\n";
		foreach ($this->products as $shopProduct) {
			$str .= $shopProduct->getSummaryLine(). "\n";
		}
		print $str;
	}
}

?>
