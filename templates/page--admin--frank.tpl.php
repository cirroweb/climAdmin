<!DOCTYPE html>
<html lang="en">
<head></head>
<body>
	
	<div class="container" style="border: 1px solid black; height: 1000px; margin: 20px auto;">  
   	<div id="content" class="clearfix">
      <div class="element-invisible"><a id="main-content"></a></div>
      <?php if ($messages): ?>
        <div id="console" class="clearfix"><?php print $messages; ?></div>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
	</div>
	
</body>
</html>
