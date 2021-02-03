import React from 'react';
import { connect } from 'react-redux';
import { toggleTodo } from '../redux/actions';
import cx from 'classnames';

const Todo = ({ todo, toggleTodo }) => (
  <li className='todo-item' onClick={() => toggleTodo(todo.id)}>
    <span className={cx('todo-item__tag', todo && todo.completed && 'todo-item__tag--completed')}>
      {todo && todo.completed ? 'DONE:' : 'TODO:'} {"  "/*This just adds whites space*/}
    </span>
    <span className={cx('todo-item__text', todo && todo.completed && 'todo-item__text--completed')}>
      {todo.content}
    </span>
  </li>
);

export default connect(
  null, // mapStateToProps
  { toggleTodo } // mapDispatchToProps
)(Todo); // component name
