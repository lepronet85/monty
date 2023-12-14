+++++++++++++++                      // Initialize four cells to 0
,>,,                               // Read first digit to second cell
[-]<                               // Loop while first digit is not zero
  ->                                 // Move pointer to product cell
  >++                               // Add two copies of first digit
  <-                                 // Move pointer back
  -                                 // Decrement first digit
>]                                 // End loop
,>,,                               // Read second digit to third cell
[-]<                               // Loop while second digit is not zero
  [->[-]>[-]<]                     // Loop 4 times:
    ->                             // Move pointer to product cell
    +                              // Add first digit to product
    <-                             // Move pointer back
  ->                               // Move pointer to multiplier cell
  -                                 // Decrement second digit
>]                                 // End loop
++++++                             // Add 48 to product (convert to ASCII)
.>                                 // Print result