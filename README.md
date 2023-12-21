# Bank-Transaction-Manager
The bank maintains a set of accounts.Each transaction specifies either a deposit (AccountNo D y) or a withdrawal (AccountNo W x). \
“Cursor” denotes the most recent transaction processed. The cursor can be moved forward to process the specified next number of transactions. The cursor can be moved backward to reverse the specified next number of transactions. \
• processF - Processes the next X transactions after the cursor. \
• processR - Undo Y transactions starting from the cursor. \
• processI (I T K) - Insert a new Transaction T immediately after the Kth transaction in the list.If inserting before cursor position, then processes this new transaction as well. \
• processD ( D A M) - Delete (up to)M(̸= 0) number of transactions of account A after/before (but excluding) the cursor’s transaction; delete in the forward direction if M > 0 and reverse direction if M < 0.Update the balance of account A accordingly. The cursor stays in its original location. \
• processC - Process ALL transactions after the cursor. \
• processS - Print all the processed transactions (until the cursor) of Account Number Y, one transaction per line.  \
• processG - Print the count of the accounts whose balance is greater than or equal to X, with respect to the current cursor position. \
• processM - Print the Account Number with the highest balance, with respect to the current cursor position. If there is more than one account number with the same highest balance, print all numbers. \
• processV - Print the balance of Account Number X, with respect to the current cursor position. \
