<?php
	$username = 'admin';
	$password = 'admin';
	$header = array( 
		'http'=>array(
		'method' => "GET",
		'header' => "Authorization: Basic ". 
		base64_encode("$username:$password") 
		) 
		);
	$context = stream_context_create($header); 
	$result = file_get_contents("http://localhost:8984/rest/?run=q3.xq", FALSE, $context);

	header('Content-type: application/xml');
	print $result;
?>

