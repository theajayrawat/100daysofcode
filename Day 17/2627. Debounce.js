// Webpage:https://leetcode.com/problems/debounce/?utm_campaign=PostD15&utm_medium=Post&utm_source=Post&gio_link_id=AovN2Ojo

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeout;
    return function(...args) {
      clearTimeout(timeout);
      timeout = setTimeout(() => fn(...args), t);
    };
  };
  
  /**
   * const log = debounce(console.log, 100);
   * log('Hello'); // cancelled
   * log('Hello'); // cancelled
   * log('Hello'); // Logged at t=100ms
   */