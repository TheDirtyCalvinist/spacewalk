package org.xwalk.core.internal;

import java.lang.String;

@XWalkAPI(createInternally = true, createExternally = true)
public class XWalkHitTestDataInternal {
    // Used in getHitTestResult.
    public int hitTestResultType;
    public String hitTestResultExtraData;

    // Used in requestFocusNodeHref (all three) and requestImageRef (only imgSrc).
    public String href;
    public String anchorText;
    public String imgSrc;

    public String[] data(){
        return new String[]{String.valueOf(hitTestResultType), hitTestResultExtraData, href, anchorText, imgSrc};
    }
}
