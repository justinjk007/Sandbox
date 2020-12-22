import React, { Component } from 'react';
// import './Button.css';

class CalcButton extends Component {
    isOperator = (val) => {
        return !isNaN(val) || val === '.' || val === '=';
    };

    render() {

        // {this.props.children}, gets us what's inside the button tag
	// Here we are replacing the button tag with our special div
        return (
            <div
                className={`button ${this.isOperator(this.props.children) ? '' : 'operator'}`}
                onClick={() => this.props.handleClick(this.props.children)}>

                {this.props.children}
            </div>
        );
    }
}
export default CalcButton;
