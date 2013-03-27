<?php
	require 'ShopProduct.class.inc';
	require 'ShopProductWriter.class.inc';
	require_once("DB.php");	
	
	
	$db = DB::connect("mysql://root:root@localhost:8889/store");
	$obj = ShopProduct::getInstance(4, $db);
	
	
	




	
	
/**----

$cd = new CdProduct("Los twists", "Los", "Twists", "10.99", "1:20:00");

$libro = new BookProduct ("La invencion de Morel", "Adolfo", "Bioy Casares", "9.99", "1200 paginas");

	print "author: " . $product1->getProducer() . "\n";

	echo "<tt><pre>". var_export($product1, TRUE) ."</pre></tt>"; 


$product1 = new ShopProduct("La invencion de Morel", "Adolfo Bioy", "Casares", 9.99);


$writer = new ShopProductWriter();
$writer->write($product1);



$libro_rayuela = new BookProduct("Rayuela", null, null, "19.99", null, "1200 paginas");


$clase_write = new ShopProductWriter();
$clase_write->addProduct($libro_rayuela);
$clase_write->write();
echo "<br>";

**/




?>

