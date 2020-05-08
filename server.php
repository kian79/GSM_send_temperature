<!DOCTYPE html>
<html>
    <meta charset="UTF8">
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
	<title>”«„«‰Â ò‰ —· œ„«</title>
<body bgcolor="#111">
	<?php
		$myfile = fopen("save.txt", "r") or die("Unable to open file!");
		$ds= fread($myfile,filesize("save.txt"));
		fclose($myfile);
	?>
	<div class="container">
	<div class="jumbotron">
	</div>
	</div>
	<center>
		<script>
			var damaj = "<?php echo $ds; ?>"
			document.write(dama+":œ„«Ì ›⁄·Ì");
			setTimeout(function(){ ;
			location.reload(); }, 10000);
		</script>
	</center>
	<div id="header"> </div>
</body>
</html>
