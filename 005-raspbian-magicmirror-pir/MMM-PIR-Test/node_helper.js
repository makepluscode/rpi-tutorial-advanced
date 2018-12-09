const Gpio = require('onoff').Gpio;
const NodeHelper = require('node_helper');

module.exports = NodeHelper.create({	
    start: function () {
		this.started = false;
    },

    socketNotificationReceived: function (notification, payload) {
		if (notification === 'CONFIG' && this.started == false) {
			const self = this;
			this.config = payload;
			this.pir = new Gpio(this.config.pin, 'in', 'both');
			this.pir.watch(function (err, value) {				
				console.log('watch : value ' + value);
				if(value) {
					self.sendSocketNotification('SHOW_ALERT', {
						title: 'PIR',
						message: 'Somebody detected!',
						timer: 4000
					});
				}
				else {
					//do nothing
				}
			});
			this.started = true;
        }
    }
});
