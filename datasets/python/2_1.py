import sys
def NxqIRYEMTTmtmMiqKDNNQPFSJMbBjBZx():
    mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd, eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql = map(int, input().split())
    paPxCyLsguCunaNIkwVLKlDZZZFWMoCt = [int(sys.aalXOjAtBigBemuIcuckMtnlmyGnijgD.readline().rstrip()) for SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN in range(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd)]
    if 0 in paPxCyLsguCunaNIkwVLKlDZZZFWMoCt:
        print(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd)
        return
    avQSZjZqSNZKEXBRrhfYLetxECfsPpOH, r = 0, 0
    dyKPLpoiodoCPkilFzAexabdRRxcVpLl = 0
    dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs = 1
    while r < mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd:
        if dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs * paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[r] <= eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql:
            dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs *= paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[r]
            r += 1
            dyKPLpoiodoCPkilFzAexabdRRxcVpLl = max(dyKPLpoiodoCPkilFzAexabdRRxcVpLl, r - avQSZjZqSNZKEXBRrhfYLetxECfsPpOH)
        elif r == avQSZjZqSNZKEXBRrhfYLetxECfsPpOH:
            r, avQSZjZqSNZKEXBRrhfYLetxECfsPpOH = r + 1, avQSZjZqSNZKEXBRrhfYLetxECfsPpOH + 1
        else:
            dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs //= paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[avQSZjZqSNZKEXBRrhfYLetxECfsPpOH]
            avQSZjZqSNZKEXBRrhfYLetxECfsPpOH += 1
    print(dyKPLpoiodoCPkilFzAexabdRRxcVpLl)
def YMOvONZSMnsTkAFSyYxzqHXKJhWCppKK(PUpArWOXTPpSQnXsATgvrltwDrDtzQKU, table):
    for rOVCAfWYCNaHzktGmNMgqpEovjEexYYl, goGXZFeMsqWjmoKRAhbyDfoGBMcUPlQO in table.items():
        if PUpArWOXTPpSQnXsATgvrltwDrDtzQKU is goGXZFeMsqWjmoKRAhbyDfoGBMcUPlQO:
            print('DEBUG:{} -> {}'.format(rOVCAfWYCNaHzktGmNMgqpEovjEexYYl, goGXZFeMsqWjmoKRAhbyDfoGBMcUPlQO), file=sys.stderr)
            return None
if __name__ == '__main__':
    NxqIRYEMTTmtmMiqKDNNQPFSJMbBjBZx()