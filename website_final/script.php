<?php

if ( isset($_GET['status']) )
{
	/* Open the file */
	$myfile = fopen("status.txt","w");

	if ( $_GET['status'] == 'Fast' )
	{
		fwrite($myfile,'0');
		header("Location: Fast.html");
	}
	
	elseif ( $_GET['status'] == 'Deep' )
	{
		fwrite($myfile,'1');
		header("Location: Deep.html");
	}
	
	elseif ( $_GET['status'] == 'Wet' )
	{
		fwrite($myfile,'2');
		header("Location: Wet.html");
	}
	
	elseif ( $_GET['status'] == 'Home' )
	{
		fwrite($myfile,'4');
		header("Location: Home.html");
	}
	
	elseif ( $_GET['status'] == 'Start' )
	{
		fwrite($myfile,'T');
		header("Location: Start.html");
	}
	
	elseif ( $_GET['status'] == 'Stop' )
	{
		fwrite($myfile,'S');
		header("Location: Stop.html");
	}
	/* Close file */
	fclose($myfile);
}



?>