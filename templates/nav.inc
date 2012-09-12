<?php
	//User vars
	global $user;
	$is_admin = '';
	$uid = $user->uid;
	$un = ($uid) ? $user->name : '' ;
	
	//grab 2nd item after domain name in url
	$arg = arg(1);

	// Create all the links for the nav
	$overview = l('Run Overview', 'run/' . $arg, array());
	$dashboard = l('Dashboard', 'run/dash', array());
	$logout = l('Logout', 'user/logout', array());
	$login = l('Login', 'user', array());
	$u_edit = l("<i class='icon-user icon-white'></i> $un", "user/$uid/edit", array("html" => TRUE));
	$admin = '';
	$people = '';
	$admin_dash = '';
	
	// Check if user has claro admin permission
	if(user_access('claro admin')) {
		$admin = '<li>'.l('Admin', 'admin/claro').'</li>';
		$people = '<li>'.l('People', 'admin/people').'</li>';
	}	

	// Check if user has claro admin permission
	if($user->uid == 1) {
		
		// Build links
		$drupmin = l('Drupmin', 'admin');
		$log = l('Log', 'admin/reports/dblog');
		
		$admin_dash = "
			<li>$drupmin</li>
			<li>$log</li>
			";
		
	}	


	//build nav based on whether there is a run # in URL
	if (is_numeric($arg)) {
		
		//test for logged in user in 'if' and 'else'
		$is_admin = ($user->uid) ? "
			 <li>$overview</li>
			 <li>$dashboard</li>
			 $admin_dash
			 $admin
			 $people
			 <li>$logout</li>
			 <li class='divider-vertical'><li>
			 $u_edit
			 "
			:
			 "<li>$login</li>";

		} else{
		
			$is_admin = ($user->uid) ? 
			"<li>$dashboard</li>
			 $admin_dash
			 $admin
			 $people
			 <li>$logout</li>
			 <li class='divider-vertical'><li>
			 $u_edit
			 "
			:
			 "<li>$login</li>";
	};
			
?>

<nav id="nav">
	<ul class="nav">
		<?php print $is_admin ?>
	</ul>
</nav>