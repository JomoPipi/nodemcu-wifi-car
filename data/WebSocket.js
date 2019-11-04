var connection = new WebSocket('ws://'+location.hostname+':81/', ['arduino']);
connection.onopen = function () {
    connection.send('Connect ' + new Date());
};
connection.onerror = function (error) {
    console.log('WebSocket Error ', error);
};
connection.onmessage = function (e) {  
    console.log('Server: ', e.data);
};
connection.onclose = function(){
    console.log('WebSocket connection closed');
};

function sendDATA() {
    var motor = document.getElementById('motor').value||512;
    var servo = document.getElementById('servo').value||90;
    var calib = document.getElementById('calib').value||10;
    connection.send(motor+':'+servo+','+calib);
}