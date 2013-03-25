<?php
	require 'ShopProduct.class.inc';
	
	

	$producto = new ShopProduct("Rayuela", "Pedro", "Cortaza", "$9.99");
	
	$cd = new CdProduct("Los twists", "Los", "Twists", "10.99", "1:20:00");

	$libro = new BookProduct ("La invencion de Morel", "Adolfo", "Bioy Casares", "9.99", "1200 paginas");


	
	print ($producto->getSummaryLine());
	
	echo "<BR>";
	
	print ($cd->getSummaryLine());
	
	echo "<BR>";	
	
	print ($libro->getSummaryLine());
	
	
	
/**----



	print "author: " . $product1->getProducer() . "\n";

	echo "<tt><pre>". var_export($product1, TRUE) ."</pre></tt>"; 


$product1 = new ShopProduct("La invencion de Morel", "Adolfo Bioy", "Casares", 9.99);


$writer = new ShopProductWriter();
$writer->write($product1);

**/

?>

