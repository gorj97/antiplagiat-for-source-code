from collections import defaultdict
class wUFHSOalIwqMuLetkAnOIHbPJgPdGsxN:
    def __init__(self, AcegNkFfeJbwzgvSHDNyCVIizOXyXAey):
        self.size = AcegNkFfeJbwzgvSHDNyCVIizOXyXAey
        self.tree = [0] * (AcegNkFfeJbwzgvSHDNyCVIizOXyXAey + 1)
    def sum(self, SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN):
        paPxCyLsguCunaNIkwVLKlDZZZFWMoCt = 0
        while SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN > 0:
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt += self.tree[SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN]
            SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN -= SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN & -SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN
        return paPxCyLsguCunaNIkwVLKlDZZZFWMoCt
    def add(self, SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN, PUpArWOXTPpSQnXsATgvrltwDrDtzQKU):
        while SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN <= self.size:
            self.tree[SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN] += PUpArWOXTPpSQnXsATgvrltwDrDtzQKU
            SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN += SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN & -SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN
AcegNkFfeJbwzgvSHDNyCVIizOXyXAey, rhqSaKiidHCQVdfElCKSruqywnInKRrL = map(int, input().split())
ZSXCWGVdRzQUkjklwKZkRKITazRLffHC = list(map(int, input().split()))
kwJohSlspmofEvMwaALFiqZnHypFazfM = defaultdict(list)
bBOXsfAjjfFzGmMJhbXwqUvSjlWCGCAn = wUFHSOalIwqMuLetkAnOIHbPJgPdGsxN(rhqSaKiidHCQVdfElCKSruqywnInKRrL + 1)
jiCXXUUaruGQYMcVZDdBwFVwoyhHJiCZ = 0
for YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX, b in zip(ZSXCWGVdRzQUkjklwKZkRKITazRLffHC, ZSXCWGVdRzQUkjklwKZkRKITazRLffHC[1:]):
    kwJohSlspmofEvMwaALFiqZnHypFazfM[b].append(YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX)
    bBOXsfAjjfFzGmMJhbXwqUvSjlWCGCAn.add(YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX + 1, 1)
    bBOXsfAjjfFzGmMJhbXwqUvSjlWCGCAn.add(b, -1)
    if YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX > b:
        bBOXsfAjjfFzGmMJhbXwqUvSjlWCGCAn.add(1, 1)
        jiCXXUUaruGQYMcVZDdBwFVwoyhHJiCZ += b
    else:
        jiCXXUUaruGQYMcVZDdBwFVwoyhHJiCZ += b - YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX
pPlLesJQNadVWaYUtEVCTadduoujnvEl = jiCXXUUaruGQYMcVZDdBwFVwoyhHJiCZ
myVEANDwwfENruuOeodwrCxIVuzfGbyp = jiCXXUUaruGQYMcVZDdBwFVwoyhHJiCZ
for PUpArWOXTPpSQnXsATgvrltwDrDtzQKU in range(2, rhqSaKiidHCQVdfElCKSruqywnInKRrL + 1):
    GRpqfBVMoWqpdbEcCkubZRUQGGZmWZlc = pPlLesJQNadVWaYUtEVCTadduoujnvEl
    xHaVKLbvFrvTVzKmuzEWcvcuZNkFTRyK = PUpArWOXTPpSQnXsATgvrltwDrDtzQKU - 1
    if xHaVKLbvFrvTVzKmuzEWcvcuZNkFTRyK in kwJohSlspmofEvMwaALFiqZnHypFazfM:
        GRpqfBVMoWqpdbEcCkubZRUQGGZmWZlc += sum((xHaVKLbvFrvTVzKmuzEWcvcuZNkFTRyK - YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX) % rhqSaKiidHCQVdfElCKSruqywnInKRrL - 1 for YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX in kwJohSlspmofEvMwaALFiqZnHypFazfM[xHaVKLbvFrvTVzKmuzEWcvcuZNkFTRyK])
    GRpqfBVMoWqpdbEcCkubZRUQGGZmWZlc -= bBOXsfAjjfFzGmMJhbXwqUvSjlWCGCAn.sum(xHaVKLbvFrvTVzKmuzEWcvcuZNkFTRyK)
    myVEANDwwfENruuOeodwrCxIVuzfGbyp = min(myVEANDwwfENruuOeodwrCxIVuzfGbyp, GRpqfBVMoWqpdbEcCkubZRUQGGZmWZlc)
    pPlLesJQNadVWaYUtEVCTadduoujnvEl = GRpqfBVMoWqpdbEcCkubZRUQGGZmWZlc
print(myVEANDwwfENruuOeodwrCxIVuzfGbyp)
