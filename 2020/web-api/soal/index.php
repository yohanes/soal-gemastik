<?php

include("secrets.php");

if (!isset($_GET["token"])) {
        highlight_file(__FILE__);
        exit;
}

$input = base64_decode($_GET["token"]);

$data = array();
$data = unserialize($input);
$data["secret"] = $secret;
$data["admin_hash"] = $super_admin_hash;

if (isset($data["user"]) && isset($data["password"])) {
        print("set hmac");
        $data["hmac"] = hash_hmac('ripemd160', $data["user"].$data["password"], $data["secret"]);
}
if (!isset($data["hmac"])) $data["hmac"] = "";

if ($data["hmac"] === $data["admin_hash"]) {
        echo "This is the flag ".$flag;
} else {
        echo "Access denied";
}       


?>
