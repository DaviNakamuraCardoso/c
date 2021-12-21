## Clab 07: Experiments with Performance
Experiments with cache, function calls and their impact on performance.

### Sum
In this experiment, I made a comparison between the classic example of a recursive sum algorithm and the more natural and efficient procedural solution that students often come up with. Despite being often shown as something 'elegant', recursion is sometimes a horrible approach to the problem. In this particular case, the  examples show that the recursive alternative is not only much slower (sometimes 10 times slower), but also cause stack overflows in medium array lengths (1,000,000 elements).
I tested 1,000,000 elements on a 'safer' language (Python). After 10 seconds, the OS killed the task.

