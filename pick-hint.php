<?
include('hints.php') ;

mt_srand( (double) microtime() * 1000000) ;

$first = mt_rand( 0, ($resTotal - 1) ) ;

print ( $res[$first] ) ;
?>

