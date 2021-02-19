def apRphnlxUcsIDtHUJyLyvNHwJmbtrVOc():
    mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd,eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql = map(int,input().split())
    paPxCyLsguCunaNIkwVLKlDZZZFWMoCt = [int(input()) for _ in range(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd)]
    xyEKWPWwqCskxfLDqxcqVPGiqOTtuOgA = False
    for SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN in range(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd):
        if paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN] == 0:
            xyEKWPWwqCskxfLDqxcqVPGiqOTtuOgA = True
            break
    if xyEKWPWwqCskxfLDqxcqVPGiqOTtuOgA:
        print(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd)
        return
    DFQAhclqmoRgzXCYALCewrNnjHOGVIeT = paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[0]
    dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP = 1
    RgyigMaPFDfVspFlEIVIlJwTjeuTwcrf = 0
    for fniJytBVSBPdOHiUhIACRvvAScLRQNie in range(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd):
        if paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[fniJytBVSBPdOHiUhIACRvvAScLRQNie] <= eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql:
            RgyigMaPFDfVspFlEIVIlJwTjeuTwcrf = max(RgyigMaPFDfVspFlEIVIlJwTjeuTwcrf,1);
        if fniJytBVSBPdOHiUhIACRvvAScLRQNie >= dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP:
            dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP = fniJytBVSBPdOHiUhIACRvvAScLRQNie + 1
            DFQAhclqmoRgzXCYALCewrNnjHOGVIeT = paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[fniJytBVSBPdOHiUhIACRvvAScLRQNie]
        while dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP < mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd and DFQAhclqmoRgzXCYALCewrNnjHOGVIeT * paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP] <= eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql:
            RgyigMaPFDfVspFlEIVIlJwTjeuTwcrf = max(RgyigMaPFDfVspFlEIVIlJwTjeuTwcrf,dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP-fniJytBVSBPdOHiUhIACRvvAScLRQNie+1)
            DFQAhclqmoRgzXCYALCewrNnjHOGVIeT *= paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP];
            dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP = dGfmdzxUVuLHxQTjvINieuLOoaVdXEAP + 1
        DFQAhclqmoRgzXCYALCewrNnjHOGVIeT = DFQAhclqmoRgzXCYALCewrNnjHOGVIeT // paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[fniJytBVSBPdOHiUhIACRvvAScLRQNie]
    print(RgyigMaPFDfVspFlEIVIlJwTjeuTwcrf)
if __name__ == "__main__":
    apRphnlxUcsIDtHUJyLyvNHwJmbtrVOc()
