package org.xwalk.core.internal;

import java.lang.String;
import java.util.HashMap;
import java.util.Map;

@XWalkAPI(createInternally = true, createExternally = true)
public class XWalkHitTestDataInternal {
    // Used in getHitTestResult.
    public int hitTestResultType;
    public String hitTestResultExtraData;

    // Used in requestFocusNodeHref (all three) and requestImageRef (only imgSrc).
    public String href;
    public String anchorText;
    public String imgSrc;

    public Map data(){
        HashMap<String, String> data = new HashMap<String, String>(5);
        data.put("hitTestResultType", String.valueOf(hitTestResultType));
        data.put("hitTestResultExtraData", hitTestResultExtraData);
        data.put("href", href);
        data.put("anchorText", anchorText);
        data.put("imgSrc", imgSrc);
        return data;
    }

    public String toString(){
        return data().toString();
    }
}
