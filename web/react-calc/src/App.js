import React, {Component} from 'react';
import './App.css';

import Button from './components/Button';
import Input from './components/Input';
import ClearButton from './components/ClearButton';


class App extends Component  {
    constructor(props){
	super(props);

	this.state = {
	    input: "",
	    prevNum: "",
	    current: "",
	    operator: ""
	};
    }

    addToInput = val => {
	this.setState({input: this.state.input + val});
    };

    addDecimal = val => {
	// Only add decimal if one doesn't exist already
	if (this.state.input.indexOf(".") === -1) {
	    // -1 returns means searched char doesn't exist
	    this.setState({input: this.state.input + val});
	}
    };

    addZeroToInput = val => {
	// Don't want zero to be added if area is empty
	if (this.state.input !== "") {
	    this.setState({input: this.state.input + val});
	}
    };

    clearDisplay = () => {
	this.setState({input: ""});
	this.setState({operator: "plus"});
	this.setState({prevNum: "0"});
    };

    add = () => {
	this.state.prevNum = this.state.input;
	this.setState({input: ""});
	this.setState({operator: "plus"});
    };

    subtract = () => {
	this.state.prevNum = this.state.input;
	this.setState({input: ""});
	this.setState({operator: "minus"});
    };

    multiply = () => {
	this.state.prevNum = this.state.input;
	this.setState({input: ""});
	this.setState({operator: "cross"});
    };

    divide = () => {
	this.state.prevNum = this.state.input;
	this.setState({input: ""});
	this.setState({operator: "slash"});
    };

    eval = () => {
	var ans;
	if (this.state.operator === "plus") {
	    ans = parseInt(this.state.input)+parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "minus") {
	    ans = parseInt(this.state.input)-parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "cross") {
	    ans = parseInt(this.state.input)*parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "slash") {
	    ans = parseInt(this.state.input)/parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else{
	    this.setState({input: "Operator not supported!"});
	}
    };

    render() {
    return (
        <div className='App'>
            <div className='calcWrapper'>
            <div className='row'>
	    <Input> {this.state.input} </Input>
	    </div>
	    <div className='row'>
                    <Button handleClick={this.addToInput} >7</Button>
                    <Button handleClick={this.addToInput} >8</Button>
                    <Button handleClick={this.addToInput} >9</Button>
                    <Button handleClick={this.divide} >/</Button>
                </div>
                <div className='row'>
                    <Button handleClick={this.addToInput} >4</Button>
                    <Button handleClick={this.addToInput} >5</Button>
                    <Button handleClick={this.addToInput} >6</Button>
                    <Button handleClick={this.multiply} >*</Button>
                </div>
                <div className='row'>
                    <Button handleClick={this.addToInput} >1</Button>
                    <Button handleClick={this.addToInput} >2</Button>
                    <Button handleClick={this.addToInput} >3</Button>
                    <Button handleClick={this.add} >+</Button>
                </div>
                <div className='row'>
                    <Button handleClick={this.addDecimal} >.</Button>
                    <Button handleClick={this.addZeroToInput} >0</Button>
                    <Button handleClick={this.eval} >=</Button>
                    <Button handleClick={this.subtract} >-</Button>
                </div>
                <div className='row'>
	        <ClearButton handleClear={this.clearDisplay}></ClearButton>
                </div>
            </div>
        </div>
    );
    }
}

export default App;
