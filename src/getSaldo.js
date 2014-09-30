function HTTPGET(url) {
    var req = new XMLHttpRequest();
    req.open("POST", url, false);
		req.setRequestHeader("Content-type","application/x-www-form-urlencoded");
    req.send("u=" + localStorage.getItem("username") + "&p=" + localStorage.getItem("password"));
    return req.responseText;
}
var getBalance = function() {
	var response = HTTPGET("http://darkbox.dead-pixel.nl/api/ming/getSaldo.php");
	var dict = {"KEY_BALANCE" : response};
    Pebble.sendAppMessage(dict,
	function(e) {
    //
  },
  function(e) {
    console.log("Error sending balance info to Pebble!");
  });
	console.log("Balance: " + response);
};

Pebble.addEventListener("ready",
  function(e) { 
		console.log("JS Ready!");
		getBalance();
  });
Pebble.addEventListener("appmessage",
	function(e) {
		getBalance();
	});
Pebble.addEventListener("showConfiguration", function() {
Pebble.openURL('http://darkbox.dead-pixel.nl/api/ming/configurable.html');
});
Pebble.addEventListener("webviewclosed", function(e) {
// webview closed
var options = JSON.parse(decodeURIComponent(e.response));
localStorage.setItem("username", options.username);
localStorage.setItem("password", options.password);
//console.log("Options = " + JSON.stringify(options));
});