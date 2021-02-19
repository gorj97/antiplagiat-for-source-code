import sys
from fractions import gcd
def FvhmgBXRhSwWdYGhpVjgfgkpwzYlkCRX(YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX, b):
    return YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX * b // gcd(YYNGEPqXKySfivSFcmpFKpQAJSkIjsAX, b)
def NxqIRYEMTTmtmMiqKDNNQPFSJMbBjBZx():
    mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd, eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql = map(int, input().split())
    paPxCyLsguCunaNIkwVLKlDZZZFWMoCt = [int(sys.aalXOjAtBigBemuIcuckMtnlmyGnijgD.readline().rstrip()) for SoVQFUTGRTfzyguoxvYZTDAuOtmejXkN in range(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd)]
    if paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.count(0) > 0:
        print(mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd)
        return
    avQSZjZqSNZKEXBRrhfYLetxECfsPpOH = 0
    r = 0
    dyKPLpoiodoCPkilFzAexabdRRxcVpLl = 0
    dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs = 1
    while r < mkZLYnKLyKDkxaWrSYCBMOeNMywJyMLd:
        if avQSZjZqSNZKEXBRrhfYLetxECfsPpOH == r:
            r += 1
            dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs *= paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[avQSZjZqSNZKEXBRrhfYLetxECfsPpOH]
            if dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs > eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql:
                dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs = 1
                avQSZjZqSNZKEXBRrhfYLetxECfsPpOH += 1
            else:
                dyKPLpoiodoCPkilFzAexabdRRxcVpLl = max(dyKPLpoiodoCPkilFzAexabdRRxcVpLl, 1)
        elif (dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs * paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[r]) <= eAZfUsAfKTSQMCGhAOPwzTBARqxsQEql:
            dnCxxOFFeCanZkqfPxJAOrbubVTvwPFs *= paPxCyLsguCunaNIkwVLKlDZZZFWMoCt[r]
            r += 1
            dyKPLpoiodoCPkilFzAexabdRRxcVpLl = max(dyKPLpoiodoCPkilFzAexabdRRxcVpLl, r - avQSZjZqSNZKEXBRrhfYLetxECfsPpOH)
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