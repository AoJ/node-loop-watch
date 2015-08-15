# Node loop watch

### Experiment, don't use it!


## Usage

	git clone
	npm install
	npm install express
	node example.js &
	ab -c 20 -n 20 localhost:11111/slow


example output

	handlers: 30, start: 389417, freezing for 505 ms due to JS
	handlers: 30, start: 389417, freezing for 1010 ms due to JS
	handlers: 30, start: 389417, freezing for 1515 ms due to JS
	handlers: 30, start: 389417, freezing for 2020 ms due to JS
	handlers: 30, start: 389417, freezing for 2525 ms due to JS
	handlers: 30, start: 389417, freezing for 3030 ms due to JS
	handlers: 30, start: 389417, freezing for 3535 ms due to JS
	handlers: 30, start: 389417, freezing for 4040 ms due to JS
	handlers: 30, start: 389417, freezing for 4545 ms due to JS
	handlers: 30, start: 389417, freezing for 5050 ms due to JS
	handlers: 30, start: 389417, freezing for 5555 ms due to JS
	handlers: 30, start: 389417, freezing for 6060 ms due to JS
	handlers: 30, start: 389417, freezing for 6565 ms due to JS
	handlers: 30, start: 389417, freezing for 7070 ms due to JS
	handlers: 30, start: 389417, freezing for 7575 ms due to JS
	handlers: 30, start: 389417, freezing for 8080 ms due to JS
	handlers: 30, start: 389417, freezing for 8585 ms due to JS
	handlers: 30, start: 389417, freezing for 9090 ms due to JS
	handlers: 30, start: 389417, freezing for 9595 ms due to JS
	handlers: 30, start: 389417, freezing for 10100 ms due to JS
	handlers: 30, start: 389417, freezing for 10605 ms due to JS
	handlers: 30, start: 389417, freezing for 11110 ms due to JS
	handlers: 30, start: 389417, freezing for 11615 ms due to JS
	handlers: 30, start: 389417, freezing for 12120 ms due to JS
	handlers: 30, start: 389417, freezing for 12625 ms due to JS
	handlers: 30, start: 389417, freezing for 13130 ms due to JS
	handlers: 30, start: 389417, freezing for 13635 ms due to JS
	handlers: 30, start: 389417, freezing for 14140 ms due to JS
	handlers: 30, start: 389417, freezing for 14645 ms due to JS
	request time 17269
	handlers: 28, start: 389417, freezed  for 15120 ms due to JS
	request time 17092
	handlers: 28, start: 389451, freezing for 505 ms due to JS
	handlers: 28, start: 389451, freezing for 1010 ms due to JS
	handlers: 28, start: 389451, freezing for 1515 ms due to JS
	handlers: 28, start: 389451, freezing for 2020 ms due to JS
	handlers: 28, start: 389451, freezing for 2525 ms due to JS
	handlers: 28, start: 389451, freezing for 3030 ms due to JS
	handlers: 28, start: 389451, freezing for 3535 ms due to JS