Module.register('MMM-PIR-Test', {
	start: function () {		
		this.sendSocketNotification('CONFIG', this.config);
		Log.info('Starting module: ' + this.name);
	},

	socketNotificationReceived: function (notification, payload) {
		if (notification === 'SHOW_ALERT') {
			this.sendNotification(notification, payload);
		}
	},
});
