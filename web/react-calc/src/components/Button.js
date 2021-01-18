import React, { Component } from 'react';
import { Button } from 'carbon-components-react';
import './Button.scss';

class CalcButton extends Component {
  isOperator = (val) => {
    return !isNaN(val) || val === '.' || val === '=';
  };

  render() {
    // {this.props.children}, gets us what's inside the button tag
    // Here we are replacing the button tag with our special div
    return (
      <Button
        kind={`${!this.isOperator(this.props.children) ? 'primary' : 'ghost'}`}
        className='button'
        onClick={() => this.props.handleClick(this.props.children)}>
        {this.props.children}
      </Button>
    );
  }
}
export default CalcButton;
