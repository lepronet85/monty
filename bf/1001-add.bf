+++++++++++++++                      // Initialize three cells to 0
,>,,                               // Read first digit to second cell
[-]<                               // Loop while digit is not zero
  ->                                 // Move pointer to sum cell
  +                                 // Add first digit to sum
  <-                                 // Move pointer back
  -                                 // Decrement first digit
>]                                 // End loop
,>,,                               // Read second digit to third cell
[-]<                               // Loop while digit is not zero
  ->                                 // Move pointer to sum cell
  +                                 // Add second digit to sum
  <-                                 // Move pointer back
  -                                 // Decrement second digit
>]                                 // End loop
++++++                             // Add 48 to sum (convert to ASCII)
.>                                 // Print result
