<?php
$s=$_GET["value"];
$myfile = fopen("save.txt", "w") or die("Unable to open file!");
fwrite($myfile, $s);
fclose($myfile);
?>