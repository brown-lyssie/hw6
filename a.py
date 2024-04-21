def Optimal_Bonus(X, B, n):
  p = [0 for i in range(n+1)] # 6 long
  # p[0] = 0
  # p[1] = 0
  for j in range(1,n+1): # 2,3,...n
    #print("j=", j)
    for i in range(j-1, 0-1, -1): # j-1, j-2,...0
      #print("j=", j, "i=", i)
      print(X[j-1], " and ", X[i-1])
      if X[j-1] > (5 + X[i-1]):
        p[j] = i
        break
  return Optimal_Bonus_Helper(B, p, n)

def Optimal_Bonus_Helper(B, p, j):
  if j == 0:
    return 0
  #print("Bonus at j=", j, B[j-1])
  return max(B[j-1] + Optimal_Bonus_Helper(B, p, p[j]), Optimal_Bonus_Helper(B, p, j-1))
  



if __name__ == "__main__":
  print("Yes")
  X_given = [8,10,15,22,26]
  B_given = [15,5,25,15,5]
  n_given=5
  print(Optimal_Bonus(X_given, B_given, n_given))